#include "main_scene.h"

MainScene::MainScene() {
  auto padding = 10.0f;

  // Layers
  auto background = new Layer(Layer::STATIC);
  AddLayer(background);
  auto elements = new Layer(Layer::STATIC);
  AddLayer(elements);

  // Background image
  auto background_image = new TexturedQuad();
  background_image->set_size(Game::instance()->width(), Game::instance()->height());
  background_image->set_texture("white.png");
  background->Add(background_image);

  // Label
  auto label = new Text();
  label->set_text("Sample label!");
  label->set_position(padding, Game::instance()->height() / 10 * 9);
  elements->Add(label);

  // Textbox
  auto textbox = new TextBox();
  textbox->text_->set_text("Sample text");
  textbox->set_position(padding, Game::instance()->height() / 10 * 8);
  elements->Add(textbox);

  // Checkbox
  auto checkbox = new Checkbox();
  checkbox->set_position(padding,
                         Game::instance()->height() / 10 * 7);
  elements->Add(checkbox);

  // Checkbox label
  auto label_cb = new Text();
  label_cb->set_text("<- Sample checkbox!");
  label_cb->set_position(checkbox->position().x + checkbox->size().width + checkbox->size().width / 2,
                         Game::instance()->height() / 10 * 7);
  elements->Add(label_cb);

  // Button
  auto button = new Button();
  button->set_text("Sample button!");
  button->set_position(padding, Game::instance()->height() / 10 * 5);
  elements->Add(button);

  // Combobox
  auto combobox = new Combobox();
  combobox->set_position(padding, Game::instance()->height() / 10 * 6);
  for (int i = 0; i < 3; ++i) {
    std::stringstream ss;
    ss << "Item " << i;
    auto item = new ComboboxItem(ss.str());
    combobox->AddItem(item);
  }
  elements->Add(combobox);

  // FPS label
  fps_ = new Text();
  elements->Add(fps_);
}

void MainScene::Update() {
  std::stringstream ss;
  ss << "FPS: " << Game::instance()->frames_per_second_;
  fps_->set_text(ss.str());
  Scene::Update();
}