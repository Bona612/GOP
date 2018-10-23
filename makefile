./main : ./src/main.o ./src/Game/Game.o ./src/Box/Box.o ./src/Box/BackStartBox.o ./src/Box/DrawCardBox.o ./src/Box/FinishBox.o ./src/Box/MissTurnBox.o ./src/Box/MoveBox.o ./src/Box/StartBox.o ./src/Box/VoidBox.o ./src/Card/Card.o ./src/Card/BackCard.o ./src/Card/AgainCard.o ./src/Card/ForwardCard.o ./src/Card/QuestionCard.o ./src/Card/SwitchCard.o ./src/Card/VoidCard.o ./src/Color/Color.o ./src/Deck/Deck.o ./src/Dice/Dice.o ./src/Game/Game.o ./src/Player/Player.o ./src/Question/Question.o ./src/Utils/Utils.o
	g++ -o ./main ./src/main.o ./src/Game/Game.o ./src/Box/Box.o ./src/Box/BackStartBox.o ./src/Box/DrawCardBox.o ./src/Box/FinishBox.o ./src/Box/MissTurnBox.o ./src/Box/MoveBox.o ./src/Box/StartBox.o ./src/Box/VoidBox.o ./src/Card/Card.o ./src/Card/BackCard.o ./src/Card/AgainCard.o ./src/Card/ForwardCard.o ./src/Card/QuestionCard.o ./src/Card/SwitchCard.o ./src/Card/VoidCard.o ./src/Color/Color.o ./src/Deck/Deck.o ./src/Dice/Dice.o ./src/Player/Player.o ./src/Question/Question.o ./src/Utils/Utils.o
	
./src/main.o : ./src/main.cpp ./src/Game/Game.h
	g++ -c ./src/main.cpp -o ./src/main.o
		
./src/Game/Game.o : ./src/Game/Game.cpp ./src/Game/Game.h ./src/Box/VoidBox.h ./src/Color/Color.h ./src/Box/DrawCardBox.h ./src/Box/MoveBox.h ./src/Box/MissTurnBox.h ./src/Box/BackStartBox.h ./src/Box/StartBox.h ./src/Box/FinishBox.h ./src/Card/Card.h ./src/Utils/Utils.h
	g++ -c ./src/Game/Game.cpp -o ./src/Game/Game.o
	
./src/Box/Box.o : ./src/Box/Box.cpp ./src/Box/Box.h
	g++ -c ./src/Box/Box.cpp -o ./src/Box/Box.o

./src/Box/BackStartBox.o : ./src/Box/BackStartBox.cpp ./src/Box/BackStartBox.h
	g++ -c ./src/Box/BackStartBox.cpp -o ./src/Box/BackStartBox.o

./src/Box/DrawCardBox.o : ./src/Box/DrawCardBox.cpp ./src/Box/DrawCardBox.h
	g++ -c ./src/Box/DrawCardBox.cpp -o ./src/Box/DrawCardBox.o

./src/Box/FinishBox.o : ./src/Box/FinishBox.cpp ./src/Box/FinishBox.h
	g++ -c ./src/Box/FinishBox.cpp -o ./src/Box/FinishBox.o

./src/Box/MissTurnBox.o : ./src/Box/MissTurnBox.cpp ./src/Box/MissTurnBox.h ./src/Utils/Utils.h
	g++ -c ./src/Box/MissTurnBox.cpp -o ./src/Box/MissTurnBox.o

./src/Box/MoveBox.o : ./src/Box/MoveBox.cpp ./src/Box/MoveBox.h ./src/Utils/Utils.h
	g++ -c ./src/Box/MoveBox.cpp -o ./src/Box/MoveBox.o

./src/Box/StartBox.o : ./src/Box/StartBox.cpp ./src/Box/StartBox.h
	g++ -c ./src/Box/StartBox.cpp -o ./src/Box/StartBox.o

./src/Box/VoidBox.o : ./src/Box/VoidBox.cpp ./src/Box/VoidBox.h
	g++ -c ./src/Box/VoidBox.cpp -o ./src/Box/VoidBox.o

./src/Card/Card.o : ./src/Card/Card.cpp ./src/Card/Card.h
	g++ -c ./src/Card/Card.cpp -o ./src/Card/Card.o

./src/Card/AgainCard.o : ./src/Card/AgainCard.cpp ./src/Card/AgainCard.h
	g++ -c ./src/Card/AgainCard.cpp -o ./src/Card/AgainCard.o

./src/Card/BackCard.o : ./src/Card/BackCard.cpp ./src/Card/BackCard.h
	g++ -c ./src/Card/BackCard.cpp -o ./src/Card/BackCard.o

./src/Card/ForwardCard.o : ./src/Card/ForwardCard.cpp ./src/Card/ForwardCard.h
	g++ -c ./src/Card/ForwardCard.cpp -o ./src/Card/ForwardCard.o

./src/Card/QuestionCard.o : ./src/Card/QuestionCard.cpp ./src/Card/QuestionCard.h ./src/Question/Question.h ./src/Card/ForwardCard.h ./src/Card/BackCard.h
	g++ -c ./src/Card/QuestionCard.cpp -o ./src/Card/QuestionCard.o

./src/Card/SwitchCard.o : ./src/Card/SwitchCard.cpp ./src/Card/SwitchCard.h
	g++ -c ./src/Card/SwitchCard.cpp -o ./src/Card/SwitchCard.o

./src/Card/VoidCard.o : ./src/Card/VoidCard.cpp ./src/Card/VoidCard.h
	g++ -c ./src/Card/VoidCard.cpp -o ./src/Card/VoidCard.o

./src/Color/Color.o : ./src/Color/Color.cpp ./src/Color/Color.h
	g++ -c ./src/Color/Color.cpp -o ./src/Color/Color.o

./src/Deck/Deck.o : ./src/Deck/Deck.cpp ./src/Deck/Deck.h ./src/Card/Card.h ./src/Card/SwitchCard.h ./src/Card/AgainCard.h ./src/Card/QuestionCard.h ./src/Card/VoidCard.h
	g++ -c ./src/Deck/Deck.cpp -o ./src/Deck/Deck.o

./src/Dice/Dice.o : ./src/Dice/Dice.cpp ./src/Dice/Dice.h
	g++ -c ./src/Dice/Dice.cpp -o ./src/Dice/Dice.o

./src/Player/Player.o : ./src/Player/Player.cpp ./src/Player/Player.h ./src/Card/Card.h
	g++ -c ./src/Player/Player.cpp -o ./src/Player/Player.o

./src/Question/Question.o : ./src/Question/Question.cpp ./src/Question/Question.h ./src/Utils/Utils.h
	g++ -c ./src/Question/Question.cpp -o ./src/Question/Question.o
	
./src/Utils/Utils.o : ./src/Utils/Utils.cpp ./src/Utils/Utils.h
	g++ -c ./src/Utils/Utils.cpp -o ./src/Utils/Utils.o

