#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <ClassName>"
    exit 1
fi

CLASS_NAME=$1
if [ -f "${CLASS_NAME}.cpp" ]; then
    echo "${CLASS_NAME}.cpp already exists"
    exit 1
fi

cat > ${CLASS_NAME}.cpp << EOL
#include "${CLASS_NAME}.hpp"
#include <iostream>

${CLASS_NAME}::${CLASS_NAME}()
{
    std::cout << "${CLASS_NAME} default constructor" << std::endl;
    return;
}

${CLASS_NAME}::${CLASS_NAME}(/*PARAMETER*/)
{
    std::cout << "${CLASS_NAME} parametrized constructor" << std::endl;
    return;
}

${CLASS_NAME}::${CLASS_NAME}(${CLASS_NAME} const &src)
{
    std::cout << "${CLASS_NAME} copy constructor" << std::endl;
    /*TODO*/;
    return;
}

${CLASS_NAME} &${CLASS_NAME}::operator=(${CLASS_NAME} const &rhs)
{
    std::cout << "${CLASS_NAME} copy assignment operator" << std::endl;
    if (this != &rhs)
    {
      /*TODO*/;
    }
    return *this;
}

${CLASS_NAME}::~${CLASS_NAME}()
{
    std::cout << "${CLASS_NAME} destructor" << std::endl;
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
    o << std::endl;
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
EOL

echo "Generated ${CLASS_NAME}.cpp with template code"