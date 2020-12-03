---
documentclass: article
papersize: a4
geometry: margin=2cm
lang: pl
title: "Sprawozdanie - projekt grafika"
author:
- Grzegorz Bujak
- Arkadiusz Markowski
- gr. 3ID11A
mainfont: Lato
monofont: Ubuntu Mono
toc: t
---

# Opis projektu

Tematem naszego projektu jest gra typu shooter 2D z widokiem z góry. Projekt korzysta
z biblioteki SDL2.

# Świat

Mapa gry jest przechowywana jako dwuwymiarowa siatka kafelków. Silnik wspiera różne
rodzaje kafelków. Są one inaczej rysowane na ekranie i elementy gry inaczej na nie
reagują.

Rodzaje kafelków, jakie do tej pory zaimplementowaliśmy to:

- Ściana (w sikniku Wall) - jest to nieprzenikalna ściana, która tworzy pokoje i
  korytarze na mapie gry. Nie przechodzą przez nie kule, ani gracz.

- Okno (w silniku Window) - jest to kafelek, przez którego można strzelać, ale nie
  można przez niego przechodzić.

- Wolna przestrzeń (w sinkiku Space) - jest to kafelek, z którego zbudowane są
  wnętrza pomieszczeń. W obrębie tych kafelków porusza się gracz. Nie zatrzymuje kul.

Kafelki w silniku gry to kwadraty o wymiarach 1.0 na 1.0. Są skalowane tylko w
momencie rysowania na ekran.

# Renderer

Renderer to klasa przechowująca dane o kamerze i oknie aplikacji (`SDL_Renderer`). Ma
metody rysujące gracza, kule i świat na ekranie.

# Kamera

`Camera` to klasa, która przed rysowaniem każdej klatki pobiera położenie kursora
myszy w oknie aplikacji i oblicza odchylenie lewego górnego rogu ekranu od
współrzędnych 0.0, 0.0. Odchylenie jest obliczane tak, żeby kamera w każdej klatce
była wyśrodkowana pomiędzy kursorem myszy, a graczem. Domyślnie jest także bardziej
zbliżona do gracza.

Oblicza też `aim_vector`. Jest to wektor dwuwymiarowy taki, że pozycja gracza +
`aim_vector` = pozycja kursora myszy. Wektor jest używany do określenia kierunku
strzelania.

# Kolizja

Kolizja jest zaimplementowana w metodach klasy `World`. Dzięki temu, że wszystko w
silniku jest kwadratem oraz plansza jest siatką kafelków, sprawdzanie kolizji ze
światem jest bardzo proste i wydajne.

Żeby uzyskać kafelek, w jakim znajduje się kwadrat, wystarczy użyć na jego
koordynatach funkcji `std::floor`. Jeśli szerokość kafelka jest taka, że po dodaniu
jej do koordynatów otrzymamy inny kafelek, należy sprawdzić też kolizję tych
kafelków. Wykonuje to ta funkcja:

```cpp
auto World::simple_collision(Point2f position, float width, bool is_piercing) -> bool {
    auto& room = *current_room();

    bool crosses_x = std::floor(position.x) != std::floor(position.x + width);
    bool crosses_y = std::floor(position.y) != std::floor(position.y + width);

    bool result = false;

    for (int x = 0; x < 1 + (int) crosses_x; x++)
        for (int y = 0; y < 1 + (int) crosses_y; y++)
            result |= room.does_collide({position.x + x, position.y + y}, is_piercing);
    
    return result;
}
```

Takie rozwiązanie nie nadaje się do kolizji gracza ze światem, bo kolizja na jednej
osi blokowałaby ruch gracza na obydwu osiach. Do kolizji gracza ze światem służy ta
metoda:

```cpp
auto World::vector_collision(Point2f position,
                             Point2f next_position,
                             float width,
                             bool is_piercing) -> Point2f {
    Point2f result;
    
    if (simple_collision({next_position.x, position.y}, width, is_piercing))
        result.x = position.x;
    else result.x = next_position.x;

    if (simple_collision({position.x, next_position.y}, width, is_piercing))
        result.y = position.y;
    else result.y = next_position.y;

    return result;
}
```
Umożliwia to przesuwanie się gracza wzdłuż ściany, gdy ten porusza się po skosie.
