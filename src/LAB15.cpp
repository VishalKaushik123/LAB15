/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Vishal/Documents/CTDProjects/LAB15/src/LAB15.ino"
/*
 * Project LAB15
 * Description:
 * Author:
 * Date:
 */

#include <cstdlib>

void myThread1(void *args);
void myThread2(void *args);
void myThread3(void *args);
void setup();
void loop();
#line 10 "c:/Users/Vishal/Documents/CTDProjects/LAB15/src/LAB15.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

os_thread_t thread1;
os_thread_t thread2;
os_thread_t thread3;

int counter = 0;

void myThread1(void *args)
{
  while (1)
  { // we must NEVER return from this function / thread
    int num = rand();
    delay(1000);
    WITH_LOCK(Serial)
    {
      Serial.println(num);
    }
  }
}

void myThread2(void *args)
{
  while (1)
  { // we must NEVER return from this function / thread
    counter++;
    delay(500);
    WITH_LOCK(Serial)
    {
      Serial.println(counter);
    }
  }
}

void myThread3(void *args)
{
  while (1)
  { // we must NEVER return from this function / thread
    delay(125);
    digitalWrite(D7, HIGH);
    delay(125);
    digitalWrite(D7, LOW);
  }
}

void setup()
{
  os_thread_create(&thread1, "thread1", OS_THREAD_PRIORITY_DEFAULT, myThread1, NULL, 1024);
  os_thread_create(&thread1, "thread2", OS_THREAD_PRIORITY_DEFAULT, myThread2, NULL, 1024);
  os_thread_create(&thread1, "thread3", OS_THREAD_PRIORITY_DEFAULT, myThread3, NULL, 1024);

  Serial.begin(9600);

  pinMode(D7, OUTPUT);
}

void loop()
{
}