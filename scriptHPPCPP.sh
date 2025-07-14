#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <ClassName>"
    exit 1
fi

CLASS_NAME=$1
HEADER_GUARD_NAME=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

#######HPP######
if [ -f "${CLASS_NAME}.hpp" ]; then
    echo "${CLASS_NAME}.hpp already exists"
    exit 1
fi

cat > ${CLASS_NAME}.hpp << EOL
#ifndef ${HEADER_GUARD_NAME}
#define ${HEADER_GUARD_NAME}

#include <iostream>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class ${CLASS_NAME} {  
public:
    ${CLASS_NAME}();
    ${CLASS_NAME}(${CLASS_NAME} const &other);
    ${CLASS_NAME} &operator=(${CLASS_NAME} const &other);
    ~${CLASS_NAME}();
private:
};

std::ostream &operator<<(std::ostream &o, ${CLASS_NAME} const &infile);

#endif
EOL

echo "Generated ${CLASS_NAME}.hpp with template code"

#######CPP######

if [ -f "${CLASS_NAME}.cpp" ]; then
    echo "${CLASS_NAME}.cpp already exists"
    exit 1
fi

cat > ${CLASS_NAME}.cpp << EOL
#include "${CLASS_NAME}.hpp"
#include <iostream>

${CLASS_NAME}::${CLASS_NAME}()
{
    std::cout << GREY << "${CLASS_NAME} default constructor" << RESET << std::endl;
    return;
}

${CLASS_NAME}::${CLASS_NAME}(${CLASS_NAME} const &other)
{
    std::cout << GREY << "${CLASS_NAME} copy constructor" << RESET << std::endl;
    /*TODO*/;
    return;
}

${CLASS_NAME} &${CLASS_NAME}::operator=(${CLASS_NAME} const &other)
{
    std::cout << GREY << "${CLASS_NAME} copy assignment operator" << RESET << std::endl;
    if (this != &other)
    {
      /*TODO*/;
    }
    return *this;
}

${CLASS_NAME}::~${CLASS_NAME}()
{
    std::cout << GREY << "${CLASS_NAME} destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const ${CLASS_NAME} &infile)
{
    o << "";
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
EOL

echo "Generated ${CLASS_NAME}.cpp with template code"
