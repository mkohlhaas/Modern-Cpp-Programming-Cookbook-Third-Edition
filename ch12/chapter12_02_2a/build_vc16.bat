cl /std:c++latest /EHsc /experimental:module /MD /c geometry-core.ixx
cl /std:c++latest /EHsc /experimental:module /internalPartition /MD /c geometry-details.cpp
cl /std:c++latest /EHsc /experimental:module /MD /c geometry-literals.ixx
cl /std:c++latest /EHsc /experimental:module /MD /c geometry.ixx
cl /std:c++latest /EHsc /experimental:module /MD /Femain main.cpp geometry-core.obj geometry-literals.obj geometry-details.obj
