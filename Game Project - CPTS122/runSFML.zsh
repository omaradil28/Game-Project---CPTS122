
rm -f SFMLapp

g++ $1 -I/opt/homebrew/Cellar/sfml/2.6.1/include -o SFMLapp -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

./SFMLapp
