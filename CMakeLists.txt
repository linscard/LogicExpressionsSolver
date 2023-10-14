cmake_minimum_required(VERSION 3.26)
project(TP1)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP1
        src/Stack.cpp
        include/Stack.h
        src/main.cpp
        src/Node.cpp
        include/Node.h
        src/errorTreatment.cpp
        include/errorTreatment.h
        src/InFixExpression.cpp
        include/InFixExpression.h
        src/Utils.cpp
        include/Utils.h
        src/PostFixExpression.cpp
        include/PostFixExpression.h
        src/TreeNode.cpp
        include/TreeNode.h
        src/Tree.cpp
        include/Tree.h
)
