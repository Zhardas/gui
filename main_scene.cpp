#include "main_scene.h"

MainScene::MainScene() {
  auto background = new Layer(Layer::STATIC);
  AddLayer(background);

  auto elements = new Layer(Layer::STATIC);
  AddLayer(elements);

  auto background_image = new TexturedQuad();
  background_image->set_size(Game::instance()->width(), Game::instance()->height());
  background_image->set_texture("black.png");
  background->Add(background_image);

  auto label = new Text("Arial", 24, false, false);
  label->set_text("Sample label!");
  label->set_position(Game::instance()->width()/2-label->size().width/2, Game::instance()->height()/10*9);
  elements->Add(label);

  auto textbox = new TextBox();
  textbox->set_texture("white.png");
  textbox->set_size(200.f, textbox->size().height);
  textbox->set_position(Game::instance()->width()/2-textbox->size().width/2, Game::instance()->height()/10*8);
  textbox->text_->set_text("Sample text");
  elements->Add(textbox);

  auto checkbox = new Checkbox();
  checkbox->set_position(Game::instance()->width()/2-checkbox->size().width/2, Game::instance()->height()/10*7);
  elements->Add(checkbox);

  auto label_cb = new Text("Arial", 24, false, false);
  label_cb->set_text("<- Sample checkbox!");
  label_cb->set_position(checkbox->position().x+ checkbox->size().width + checkbox->size().width/2, Game::instance()->height()/10*7);
  elements->Add(label_cb);

  auto button = new Button();
  button->set_text("Sample button!");
  button->set_position(Game::instance()->width()/2-button->size().width/2, Game::instance()->height()/10*2);
  elements->Add(button);

}

void MainScene::Update() {

  Scene::Update();
}