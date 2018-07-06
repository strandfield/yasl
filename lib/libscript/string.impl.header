


#include <string>

#include <QString>

namespace script
{

class Engine;
class Class;

std::string get_string_typename();
void register_string_type(Class cla);

namespace string
{

inline QString convert(const std::string & str) { return QString::fromUtf8(str.data(), str.size()); }

} // namespace string

} // namespace script