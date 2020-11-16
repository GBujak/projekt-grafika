#include <SDL2/SDL.h>
#include <core_functions.hpp>
#include <input_state.hpp>
#include <error.hpp>
#include <world.hpp>
#include <world_config.hpp>
#include <camera.hpp>

auto delay_at_fps(Uint32 last_tick, int fps) -> Uint32 {
    auto new_tick = SDL_GetTicks();
    if (fps < 0) return new_tick;

    auto min_frame_time = (Uint32) 1000 / fps;
    auto last_frame_time = new_tick - last_tick;
    if (last_frame_time < min_frame_time) SDL_Delay(min_frame_time - last_frame_time);
    return new_tick;
}

auto main_loop(SDL_Window* window, int fps_limit) -> std::optional<Error> {

    WorldConfig test;
    test.floor = {{
        {Tile::Type::Wall}, {}, {}, {}, {},
        {}, {}, {}, {}, {},
        {}, {}, {}, {}, {},
        {Tile::Type::Wall}, {}, {}, {}, {}, 
        {}, {}, {}, {}, {},
    }, 5, 5};
    test.player_start = {0, 0};

    World world {test};

    Camera camera {{1280, 720}};

    bool should_exit = false;
    SDL_Event event;
    auto last_tick = SDL_GetTicks();
    auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    auto input_state = InputState::next();

    while (!should_exit) {
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) should_exit = true;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        input_state = InputState::next();

        world.player().update(&input_state, last_tick);
        camera.draw(renderer, world, input_state);

        SDL_RenderPresent(renderer);

        // Limit fps
        last_tick = delay_at_fps(last_tick, fps_limit);
    }

    SDL_DestroyRenderer(renderer);

    return {};
}
