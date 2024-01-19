#!/bin/bash
    

echo "Select an option:"
echo "1. Compile"
echo "2. Compile and run"
echo "3. Run"
echo "4. Delete executable"
echo "5. Exit"



read -p "Enter your choice: " choice
read -p "Enter the appname (if it exsists) : " appname

case $choice in
    1)
        g++ -c main.cpp
        g++ main.o -o ${appname} -lsfml-graphics -lsfml-window -lsfml-system
        echo "program compiled."
        ;;
    2)
       
        g++ -c main.cpp
        g++ main.o -o $appname -lsfml-graphics -lsfml-window -lsfml-system
        ./$appname
        ;;
    3)
       
        ./$appname
        ;;
    4)
        rm main.o
        rm $appname
        echo "Executable deleted."
        ;; 
    5)
        
        echo "ok"
        ;;
    
    *)
        echo "Invalid choice."
        ;;
esac
