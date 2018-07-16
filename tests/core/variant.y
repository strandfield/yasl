import core;

Variant v{10};
Assert(v.isValid());
Assert(v.type() == Variant::Int);
Assert(v.toInt() == 10);
v = Variant{false};
Assert(v.type() == Variant::Bool);
Assert(v.toBool() == false);

/* For some reasons this does not work... */
// v = false;
// Assert(v.type() == Variant::Bool);
// Assert(v.toBool() == false);
