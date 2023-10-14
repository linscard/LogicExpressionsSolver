cmake_minimum_required(VERSION 3.26)
project(TP1)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP1
        Stack.cpp
        Stack.h
        main.cpp
        Node.cpp
        Node.h
        errorTreatment.cpp
        errorTreatment.h
        InFixExpression.cpp
        InFixExpression.h
        Utils.cpp
        Utils.h
        PostFixExpression.cpp
        PostFixExpression.h
        TreeNode.cpp
        TreeNode.h
        Tree.cpp
        Tree.h
)
