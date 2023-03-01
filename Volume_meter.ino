#define MICROPHONE A0

int o = analogRead(MICROPHONE); // received signal from pin A0
int background_noise_level = 0;

void setup() {
  // Set inputs and outputs
  pinMode(MICROPHONE, INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  // Listen for background noise  
  const int noise_tests = 10;
  int noise_levels[noise_tests];
  for(int i = 0;i<noise_tests;i++){
    noise_levels[i] = analogRead(MICROPHONE);
  }
  int noise_sum = 0;
  for(int i = 0;i<noise_tests;i++){
    noise_sum += noise_levels[i];
  }

  background_noise_level = noise_sum / noise_tests;
}

void clear(const int max){
  for(int i = 0;i < max; i++){  
    digitalWrite(2+i,LOW);
  }
}

void displayIntensity(const int intensity, const int max){
  for(int i = 0;i < intensity; i++){
    if(i > max) return;
    digitalWrite(2+i,HIGH);
  }
}


void loop() {
  o = analogRead(MICROPHONE);
  clear(4);
  displayIntensity((o - background_noise_level),4);
}
