#include <SDL3/SDL.h>
#include <iostream>
#include <random>
#include <vector>

struct Line {
    float x1, y1, x2, y2;
    Uint8 r, g, b;
};

struct Point {
    float x, y;
    Uint8 r, g, b;
};

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Random number generation setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> x_dist(0.0f, 1280.0f);
    std::uniform_real_distribution<float> y_dist(0.0f, 1024.0f);
    std::uniform_int_distribution<int> color_dist(0, 255);

    // Declare containers for lines and points
    std::vector<Line> lines;
    std::vector<Point> points;

    SDL_Event e;
    bool quit = false;
    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        // Generate new random lines each frame
        lines.clear();
        for (int i = 0; i < 10; ++i) {
            Line line;
            line.x1 = x_dist(gen);
            line.y1 = y_dist(gen);
            line.x2 = x_dist(gen);
            line.y2 = y_dist(gen);
            line.r = color_dist(gen);
            line.g = color_dist(gen);
            line.b = color_dist(gen);
            lines.push_back(line);
        }

        // Generate new random points each frame
        points.clear();
        for (int i = 0; i < 20; ++i) {
            Point point;
            point.x = x_dist(gen);
            point.y = y_dist(gen);
            point.r = color_dist(gen);
            point.g = color_dist(gen);
            point.b = color_dist(gen);
            points.push_back(point);
        }

        // Render the green square
        //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        //SDL_RenderFillRect(renderer, &greenSquare);

        // Clear the screen with black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render random lines
        for (const auto& line : lines) {
            SDL_SetRenderDrawColor(renderer, line.r, line.g, line.b, 255);
            SDL_RenderLine(renderer, line.x1, line.y1, line.x2, line.y2);
        }

        // Render random points
        for (const auto& point : points) {
            SDL_SetRenderDrawColor(renderer, point.r, point.g, point.b, 255);
            SDL_RenderPoint(renderer, point.x, point.y);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}