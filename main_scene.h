#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include <scene/scene.h>
#include <objects/textured_quad.h>
#include <objects/text.h>
#include <objects/common/button.h>
#include <objects/common/textbox.h>
#include <objects/common/checkbox.h>
#include <objects/common/listbox.h>
#include <list>
#include <cmath>

class MainScene: public Scene {
 private:

 public:
  MainScene();
  void Update();
};

#endif  // MAIN_SCENE_H_
