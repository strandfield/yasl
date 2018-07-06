import core;

List<int> from_array(const Array<int> & a)
{
  List<int> ret;
  ret.reserve(a.size());
  for(int i(0); i < a.size(); ++i)
  {
    ret.append(a[i]);
  }
  return ret;
}

List<int> l = from_array([1, 2, 3, 4, 5]);
l.back() = 0;
print(l.length());
print(l.last());
