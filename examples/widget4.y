import core;
import gui;
import widgets;

int MyCloseEvent = Event::registerEventType(-1);
print(MyCloseEvent);

class MyWidget : Widget
{
public:
  MyWidget() = default;
  ~MyWidget() = default;
  
protected:
  bool event(Event &e)
  {
    if(e.type() != MyCloseEvent)
      return Widget::event(e);

    this.close();
    return true;
  }

  void resizeEvent(ResizeEvent & e)
  {
    Size s = e.size();
    setWindowTitle(String::number(s.width()) + "x" + String::number(s.height()));
    
    if(s.width() < 200)
    {
      Event my_event{MyCloseEvent};
      App::sendEvent(this, my_event);
    }
  }
};

MyWidget & w = newWidget<MyWidget>();
w.show();

App::start();