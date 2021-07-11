/*
 * Project LAB15
 * Description:
 * Author:
 * Date:
 */

#include <cstdlib>

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

os_thread_t thread1;
os_thread_t thread2;
os_thread_t thread3;

int counter = 0;

// prints rand num to serial every 1 second
void myThread1(void *args)
{
  while (1)
  { 
    int num = rand();
    delay(1000);
    WITH_LOCK(Serial)
    {
      Serial.println(num);
    }
  }
}

// increaments counter every half a second
void myThread2(void *args)
{
  while (1)
  { 
    counter++;
    delay(500);
    WITH_LOCK(Serial)
    {
      Serial.println(counter);
    }
  }
}

// flashes LED every 1/4 of a second
void myThread3(void *args)
{
  while (1)
  { 
    delay(125);
    digitalWrite(D7, HIGH);
    delay(125);
    digitalWrite(D7, LOW);
  }
}

void setup()
{
  // initialize threads
  os_thread_create(&thread1, "thread1", OS_THREAD_PRIORITY_DEFAULT, myThread1, NULL, 1024);
  os_thread_create(&thread1, "thread2", OS_THREAD_PRIORITY_DEFAULT, myThread2, NULL, 1024);
  os_thread_create(&thread1, "thread3", OS_THREAD_PRIORITY_DEFAULT, myThread3, NULL, 1024);

  Serial.begin(9600);

  pinMode(D7, OUTPUT);
}

void loop()
{
}