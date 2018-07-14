import core;

Line l{0, 0, 10, 10};
Assert(l.x1() == 0);
Assert(l.y1() == 0);
l.translate(Point{10, 10});
Assert(l.x1() == 10);
Assert(l.y1() == 10);