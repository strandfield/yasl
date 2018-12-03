import core;
import gui;
import widgets;

class MyWidget : Widget
{
public:
  MyWidget() = default;
  ~MyWidget() = default;
  
public:
    void sizeTreshold()
    {
        emit(sizeTreshold);
    }
  
protected:
  void resizeEvent(ResizeEvent & e)
  {
    Size s = e.size();
    setWindowTitle(String::number(s.width()) + "x" + String::number(s.height()));
    
    if(s.width() < 200)
        emit(sizeTreshold);
  }
};

MyWidget & w = newWidget<MyWidget>();
//w.setWindowTitle("Hello there !");
w.show();
Object::connect(w, MyWidget::sizeTreshold, w, Widget::close);

App::start();