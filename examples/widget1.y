import core;
import gui;
import widgets;

class MyWidget : Widget
{
public:
  MyWidget() = default;
  ~MyWidget() = default;
  
protected:
  void resizeEvent(ResizeEvent & e)
  {
    Size s = e.size();
    setWindowTitle(String::number(s.width()) + "x" + String::number(s.height()));
  }
};

MyWidget & w = newWidget<MyWidget>();
//w.setWindowTitle("Hello there !");
w.show();

App::start();