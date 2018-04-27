#ifndef MENUAPP_H
#define MENUAPP_H

#include <memory>
#include <vector>

#include "baseappinst.hpp"
#include "mainmenu.hpp"
#include "circle.h"
#include "object.hpp"

using namespace cpp_prosto::application;

struct menuApp : baseAppInst
{
  enum class eMenuState : unsigned
  {
    START
   ,ABOUT
   ,EXIT
   ,START_EASY
   ,START_MEDIUM
   ,START_HARD
   ,START_HARD_NORMAL
   ,START_HARD_VERY
  };

  menuApp();

private:
  void v_init() override;
  void v_menu() override;
  void v_application() override;
  void v_exit() override;

  void keyEvent(GLFWwindow *, int, int, int, int) override;
  void mouseKeyEvent(GLFWwindow *, int, int, int) override;

  void menu_key_processing(int, int);
  void draw_menu();

  void app_init();
  void app_key_processing(int, int);
  void app_processing();
  void app_draw();

  void init_a();
  void init_b();
  void init_c();
  void init_d();

private:
  bool mIsPause{true};

  eMenuState  mMenuState;
  Menu        mMenu;

  object mObj;

  std::vector< std::unique_ptr<circle> > mvCircles;
};

#endif // MENUAPP_H
