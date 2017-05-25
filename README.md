# Kompileerimine
Teegi kompileerimiseks on vaja:
  1. CMake 3.1 või uuem
  2. TDM-GCC-32, millest testitud on järgnevad versioonid:
    * tdm-1 4.9.2
    * tdm-1 5.1.0

# Kasutamine
## Initsialiseerimine
```cpp
Game *engine = Game::instance();
engine->Initialize("Kasutajaliides", 600, 400);
```
Initialize() parameetriteks on kuvatava akna tiitel (std::string), akna laius (uint16_t) ja akna kõrgus (uint16_t) pikslites.

## Elutsükkel
```cpp
MSG message;
while (engine->running()) {
  if (PeekMessage(&message, engine->window_handle(), 0, 0, PM_REMOVE)) {
    TranslateMessage(&message);
    DispatchMessage(&message);
  }
  engine->Loop();
}
```
Selline näeb välja kõige tüüpilisem Windowsi elutsükkel, millele on lisatud TranslateMessage(), mis aitab klaviatuuri klahvivajutuste tõlkel tähtedeks.

## Stseen
Kuvatava stseeni määramine käib alljärgnevalt:
```cpp
engine->scene_ = std::make_shared<MainScene>();
```
See eeldab, et on Scene klassi põhjal tehtud alamklass, mis antud näidises on nimetatud MainScene.

Tühja stseeni näidiskood:

MainScene.cpp
```cpp
#include "main_scene.h"

MainScene::MainScene() {

}

void MainScene::Update() {
  Scene::Update();
}
```

MainScene.h
```cpp
#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include <scene/scene.h>

class MainScene: public Scene {
 private:
 public:
  MainScene();
  void Update();
};

#endif  // MAIN_SCENE_H_
```

## Objektide kuvamine
Esmalt on vaja teha uus kuvamise kiht (Layer), mis võib olla kas staatiline või dünaamiline. Staatiline kihi objektide verteksite informatsiooni ei saa muuta (ehk objektide värvi ega tekstuuri asukohta ei saa muuta), aga staatiline kiht on kõvasti efektiivsem.

Staatilise ja dünaamilise kihi loomine ja lisamine stseenile:
```cpp
auto staatiline_kiht = new Layer(Layer::STATIC); // Staatilise kihi loomine
AddLayer(staatiline_kiht); // Staatilise kihi lisamine stseenile
auto dynaamiline_kiht = new Layer(Layer::DYNAMIC); // Dünaamilise kihi loomine
AddLayer(dynaamiline_kiht); // Dünaamilise kihi lisamine stseenile
```

Peale kihtide tegemist on vaja ainult kuvatav objekt luua ning see tseenile lisada:
```cpp
// Tekstiväli
auto textbox = new TextBox(); // Uue tekstivälja loomine
textbox->text_->set_text("Sample text"); // Tekstivälja esialgse sisu määramine
textbox->set_position(10.0f, 100.0f); // Tekstivälja asukoha määramine (x-koordinaat ja y-koordinaat)
staatiline_kiht->Add(textbox); // Tekstivälja lisamine staatilisele kihile

// Nupp koos sündmusega
auto button = new Button(); // Uue nupu loomine
button->set_text("Kliki mind!"); // Nupu teksti määramine
button->set_position(10.0f, 200.0f); // Asukoha määramine
button->events_onclick_.push_back([button]() { // Nupuvajutuse funktsiooni lisamine
    button->set_text("Nupule vajutati!"); // Nupuvajutusel muudab nupu teksti
    return true; // Tagastatakse tõeväärtus, mis tähendab, et rohkem sama sündmusega ei tegeleta. Vastasel korral saab nupust "läbi" klikkida.
  });
staatiline_kiht->Add(button); // Nupu lisamine staatilisele kihile
```

