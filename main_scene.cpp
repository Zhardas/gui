#include "main_scene.h"

MainScene::MainScene() {
  // Layers
  auto background = new Layer(Layer::STATIC);
  AddLayer(background);
  auto elements = new Layer(Layer::STATIC);
  AddLayer(elements);

  // Background image
  auto background_image = new TexturedQuad();
  background_image->set_size(Game::instance()->width(), Game::instance()->height());
  background_image->set_texture("white.png");
  background_image->set_color(0xff404040);
  background->Add(background_image);

  // Label
  auto label = new Text("Arial", 24, false, false);
  label->set_text("Sample label!");
  label->set_position(Game::instance()->width() / 2 - label->size().width / 2, Game::instance()->height() / 10 * 9);
  elements->Add(label);

  // Textbox
  auto textbox = new TextBox();
  textbox->set_texture("white.png");
  textbox->set_size(200.f, textbox->size().height);
  textbox->set_position(Game::instance()->width() / 2 - textbox->size().width / 2, Game::instance()->height() / 10 * 8);
  textbox->text_->set_text("Sample text");
  elements->Add(textbox);

  // Checkbox
  auto checkbox = new Checkbox();
  checkbox->set_position(Game::instance()->width() / 2 - checkbox->size().width / 2,
                         Game::instance()->height() / 10 * 7);
  elements->Add(checkbox);

  // Checkbox label
  auto label_cb = new Text("Arial", 24, false, false);
  label_cb->set_text("<- Sample checkbox!");
  label_cb->set_position(checkbox->position().x + checkbox->size().width + checkbox->size().width / 2,
                         Game::instance()->height() / 10 * 7);
  elements->Add(label_cb);

  // Listbox
  auto listbox = new Listbox();
  listbox->set_position(Game::instance()->width() / 2 - listbox->size().width / 2, Game::instance()->height() / 10 * 6);
  auto lb_text = new Text("Arial", 24, false, false);
  lb_text->set_text("test");
  listbox->add_item(lb_text);
  listbox->add_item(new Checkbox());
  auto lb_texture = new TexturedQuad();
  lb_texture->set_texture("white.png");
  lb_texture->set_color(0xffaa0000);
  listbox->add_item(lb_texture);
  elements->Add(listbox);

  // Button
  auto button = new Button();
  button->set_text("Sample button!");
  button->set_position(Game::instance()->width() / 2 - button->size().width / 2, Game::instance()->height() / 10 * 2);
  elements->Add(button);

}

void MainScene::Update() {

  Scene::Update();
}