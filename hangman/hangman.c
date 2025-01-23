#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char words[][100] = {
    "apple", "banana", "cherry", "grape", "orange", "peach", "pear", "plum", "kiwi", "mango",
    "lemon", "lime", "apricot", "melon", "papaya", "guava", "date", "fig", "coconut", "avocado",
    "carrot", "potato", "tomato", "onion", "pepper", "garlic", "broccoli", "cabbage", "spinach", "lettuce",
    "cucumber", "zucchini", "pumpkin", "celery", "radish", "beet", "parsnip", "turnip", "cauliflower", "peas",
    "horse", "tiger", "eagle", "snake", "rabbit", "monkey", "whale", "dolphin", "shark", "zebra",
    "koala", "panda", "hippo", "rhino", "wolf", "fox", "deer", "lion", "bear", "camel",
    "ocean", "river", "mountain", "forest", "desert", "valley", "island", "beach", "volcano", "cave",
    "school", "pencil", "eraser", "notebook", "teacher", "student", "homework", "classroom", "blackboard", "exam",
    "planet", "galaxy", "comet", "asteroid", "rocket", "spaceship", "satellite", "gravity", "orbit", "star",
    "computer", "keyboard", "mouse", "monitor", "printer", "router", "server", "internet", "software", "hardware"
};

const char stickmen[][7][15] = {
	{"  ---------\n",
	"          |\n",
	"          |\n",
	"          |\n",
	"          |\n\n"},
	{"  ---------\n",
	"  |      |\n",
	"  O      |\n",
	"         |\n",
	"         |\n\n"},
	{"  ---------\n",
	"  |      |\n",
	"  O      |\n",
	"  |      |\n",
	"         |\n\n"},
	{"  ---------\n",
	"  |      |\n",
	"  O      |\n",
	"  |/     |\n",
	"         |\n\n"},
	{"  ---------\n",
	"  |       |\n",
	"  O       |\n",
	" \\|/      |\n",
	"          |\n\n"},
	{"  ---------\n",
	"  |       |\n",
	"  O       |\n",
	" \\|/      |\n",
	"  /       |\n\n"},
	{"  ---------\n",
	"  |       |\n",
	"  O       |\n",
	" \\|/      |\n",
	"  /\\      |\n\n"},
};

int num;
int wordLen;
char solution[100];
char guess[200];
int wrongs = -1;
int guessesLeft;
int errorCode;
char charGuessed;


void clearConsole() {
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux/macOS
    #endif
}

int randomInt(){
	srand(time(0));
	int random = rand() % 100;
	return random;
}

void initializeGuess(){
	for(int i = 0; i <= wordLen * 2; i += 2){
		strncat(guess, "_", i);
		strncat(guess, " ", (i+1));
	};
}

int checkInput(){
	char currGuessesLeft = guessesLeft;
    for(int i = 0; i < wordLen; i++){
		if(guess[i * 2 + 1] == charGuessed){
			printf("Yo ass already guessed this.");
			return 1;
		}
        if(solution[i] == charGuessed && guess[i * 2 + 1] != charGuessed){
            guess[i * 2 + 1] = charGuessed;
            guessesLeft--;
        }
    }
	if(currGuessesLeft == guessesLeft){
		printf("You messed up bro.\n");
		wrongs++;
		return 2;
	}
	return 0;
}

void initialize(){
	num = randomInt();
	strcpy(solution, words[num]);
	wordLen = strlen(solution);
	guessesLeft = wordLen;
	initializeGuess();
}

void drawStickMan(int index){
	for(int i = 0; i < 5; i++){
		printf("%s", stickmen[index][i]);
	}
}

void play(){
	int counter = 0;
	while(1){
		counter++;
		clearConsole();
		if(wrongs >= 0){
			drawStickMan(wrongs);
		}
		if(errorCode == 1){
			printf("You already guessed this tho.\n");
		}else if(errorCode == 2){
			printf("You messed up bro.\n");
		}
		printf("%d\n", counter);
		printf("\n");
		printf("The Guess looks like this: %s\n", guess);
		printf("Which character do you want to guess: ");
		scanf("%c", &charGuessed);
		while (getchar() != '\n');
		printf("\nThe char you guessed is: %c\n", charGuessed);
		errorCode = checkInput();
		printf("%s\n", guess);
		if(guessesLeft == 0){
			printf("Congrats! You win! The word was: %s", solution);
		}else {
			printf("Only %d more letters needed!\n", guessesLeft);
		}
		if(wrongs == 6){
			printf("Yo ass lost man. Womp womp.\n");
			break;
		}
		printf("\n");
		if(guessesLeft == 0){
			break;
		}
	}
}

int main(){
	initialize();
	play();
	return 0;
}
