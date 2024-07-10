#include "parser.hpp"

#include <iostream>

#include <boost/spirit/home/x3.hpp>

namespace async {

// text\ntext\n{\n\n}\n

namespace x3 = boost::spirit::x3;

struct bracket_tag;

auto first_rule = x3::rule<bracket_tag, std::string>() = +(x3::char_);

auto end_rule = first_rule;  //% x3::eol;

std::string parser::parse_command(std::string_view input_data) {
  std::string result;
  if (auto ok = x3::phrase_parse(input_data.begin(), input_data.end(), end_rule,
                                 x3::eol, result);
      ok) {
    return result;
  }

  // Запись ошибки.

  return {};
}

}  // namespace async