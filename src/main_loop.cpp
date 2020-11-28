#include <SDL2/SDL.h>
#include <core_functions.hpp>
#include <input_state.hpp>
#include <error.hpp>
#include <world.hpp>
#include <world_config.hpp>
#include <camera.hpp>
#include <consts.hpp>
#include <renderer.hpp>

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
        {Tile::Type::Wall}, {}, {}, {}, {Tile::Type::Window},
        {}, {}, {}, {}, {},
        {}, {}, {}, {}, {},
        {Tile::Type::Wall}, {}, {}, {}, {}, 
        {}, {}, {}, {}, {},
    }, 5, 5};

    World world {test};
    Player player {{2, 2}};

    bool should_exit = false;
    SDL_Event event;
    auto last_tick = SDL_GetTicks();
    auto sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Renderer renderer{sdl_renderer, {1280, 720}};

    auto input_state = InputState::next();

    while (!should_exit) {
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) should_exit = true;
        }

        renderer.clear();
        input_state = InputState::next();
        renderer.update(input_state, player.position());

        player.update(&input_state, renderer.camera().aim_vector(), last_tick);
        world.update(last_tick);

        renderer.draw_world(world);
        renderer.draw_player(player);
        renderer.present();

        // Limit fps
        last_tick = delay_at_fps(last_tick, -1);
    }

    SDL_DestroyRenderer(sdl_renderer);
    return {};
}
