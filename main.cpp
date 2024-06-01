#include <cstdlib>
#include <string>

std::string removeNewlinesAndHyphen(const std::string &input) {
  std::string result;
  result.reserve(input.length());

  for (size_t i = 0; i < input.length(); ++i) {
    char c{input[i]};
    bool nextEnd{i < input.length() - 1 &&
                 (input[i + 1] == '\n' || input[i + 1] == '\r')};

    if (c != '-' && (c != '\n' || c != '\r') && nextEnd) {
      result += c;
      result += ' ';
      continue;
    }

    if (c == '-' && nextEnd || (c == '\n' || c == '\r')) {
      continue;
    }

    result += c;
  }

  return result;
}
int main(int argc, char *argv[]) {
  if (argc <= 1) {
    return 1;
  }

  std::string cmd{"echo '"};
  cmd += removeNewlinesAndHyphen(argv[1]);
  cmd += "' | xclip -selection clipboard";
  std::system(cmd.c_str());

  return 0;
}
