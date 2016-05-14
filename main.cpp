#include <game.h>
#include "./main_scene.h"

int main() {
  Game *engine = Game::instance();
  engine->Initialize("Sample GUI", 600, 400);
  engine->scene_ = std::make_shared<MainScene>();
  engine->renderer_->color_.r = 0;
  engine->renderer_->color_.g = 0;
  engine->renderer_->color_.b = 0;

  MSG message;
  while (engine->running()) {
    if (PeekMessage(&message, engine->window_handle(), 0, 0, PM_REMOVE)) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
    engine->Loop();
  }

  return 0;
}
