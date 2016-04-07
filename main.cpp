#include <game.h>
#include "./main_scene.h"

int main() {
  Game *game = Game::instance();
  game->Initialize("Sample GUI", 600, 400);
  game->scene_ = std::make_shared<MainScene>();
  game->renderer_->color_.r = 0;
  game->renderer_->color_.g = 0;
  game->renderer_->color_.b = 0;

  MSG message;
  while (game->running()) {
    if (PeekMessage(&message, game->window_handle(), 0, 0, PM_REMOVE)) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
    game->Loop();
  }

  return 0;
}
