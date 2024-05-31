## Desktop Business App 

### Project Rules

#### General

1. File names should be in PascalCase

    for example: 
        
        SomeClass.cpp
2. Class, enum class, struct should be in PascalCase
    
    for example:
    
        class SomeClass {};
3. Interface classes should start with an 'i'
    
    for example: 
    
        class iSomeClass {};
4. Interface specialized for different context should add suffix
    
    for example: 
    
        class iSomeClass**Context**
5. Public interfaces shall have short brief
6. Methods or free functions should be in camelCase
    
    for example: 
        
        void functionInSomeClass() {}
7. Namespaces shall be in snake_case
8. Namespaces shall be up to three levels deep
    
    for example: 
        
        some::example::here
9. It is forbidden to use 'using namespaces' 

### Enumerations
1. Enum types shall
    - have assigned values 
    - inherit from basic types
    - fields shall start with 'c' letter 
    
    for example: 

        enum class EnumClass : std::uint8_t
        {
            cValue = 1,
        }

### Tests
1. Tests shall
    - keep the name as much as possible descriptive
    - have their fixture placed in hpp file
    - have tests TEST, TEST_F, TEST_P, etc. placed in cpp file
    - if fixture is not present, only cpp should be introduced
    - be introduced for each public method except simple getters

    for example:
    
        int value{2};
        int getValue() 
        {
            return value;
        }

### CI policies
1. Each pull request should perform
    - clang-format check
    - valgrind check
    - build and run tests
    

<!-- // data should be separated by context
// if there's general class, it should have it's own directory
// example:
// class Patient and Person are introduced in single file
// class Doctor has been created and it will contain some
// of the data that Patient has (Person)
// Person shall be moved to separated file and directory
// all objects that are part of the Person will be moved
// to the personal_data directory and will own files
// Person has sex, then person.h and sex.h


/**
 * represents both personal and medical data of patient.
 * It includes personal information such as the patients' name, address
 * identification number and contact details. It manages financial
 * data connected to particular patient. It contains finished
 * and planned treatment informations.
 */



// For each PUBLIC method in the class, there should be at least test -->
