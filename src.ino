//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Board Computer 2
// 
// Made by roberto debarba

const int ledRgbPins[] = { 3, 2, 1 };
const int buttonPins[] = { 12, 11, 10, 9 };

void setupEntries() {	
	for (int i = 0; i < 4; i++) {	
		pinMode(buttonPins[i], INPUT);
	}

	for (int i = 0; i < 3; i++) {	
		pinMode(ledRgbPins[i], OUTPUT);
	}
}

void setup() {
	setupEntries();
}

void startCar() {	
	digitalWrite(ledRgbPins[0], LOW);
	digitalWrite(ledRgbPins[1], LOW);
	digitalWrite(ledRgbPins[2], HIGH);
}

void stopCar() {	
	digitalWrite(ledRgbPins[0], HIGH);
	digitalWrite(ledRgbPins[1], LOW);
	digitalWrite(ledRgbPins[2], LOW);
}

boolean isPressed(int buttonKey) {
	return (digitalRead(buttonPins[buttonKey]) == HIGH);
}

boolean checkStart() {	
	const int PORTA = 0;
	const int CINTO = 1;
	const int MARCHA = 2;
	const int EMBREAGEM = 3;
	return (isPressed(PORTA) && isPressed(CINTO) && !isPressed(MARCHA)
		|| isPressed(PORTA) && isPressed(CINTO) && isPressed(MARCHA) && isPressed(EMBREAGEM));
}

void loop() {
	if (checkStart()) {	
		startCar();
	} else {		
		stopCar();
	}
}

