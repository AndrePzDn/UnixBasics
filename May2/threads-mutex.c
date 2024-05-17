#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int g_v = 0;

void* do_increment_work() {
  pthread_t t_id =  pthread_self();
  printf("Thread[%lu] - doing increment work...\n", t_id);
  sleep(1);
  g_v++;
  printf("Thread[%lu] -  inc: g_v[%d].\n", t_id, g_v);
  printf("Thread[%lu] - increment done.\n", t_id);
  return NULL;
}

void* do_decrement_work() {
  pthread_t t_id =  pthread_self();
  printf("Thread[%lu] - doing decrement work...\n", t_id);
  sleep(1);
  g_v--;
  printf("Thread[%lu] - done decrement.\n", t_id);
  return NULL;
}


int main(int argc, char** argv) {

  int threads = 8;
  pthread_t inc_thread_ids[threads];
  pthread_t dec_thread_ids[threads];

  for (int i = 0; i < threads; i++) {
    int t_status =
      pthread_create(&inc_thread_ids[i], NULL, do_increment_work, NULL);
    if (t_status == -1) {
      perror("Error creating thread.");
      return 1;
    }
  }

  for (int i = 0; i < threads; i++) {
    int t_status =
      pthread_create(&inc_thread_ids[i], NULL, do_increment_work, NULL);
    if (t_status == -1) {
      perror("Error creating thread.");
      return 1;
    }
  }

  for (int i = 0; i < threads; i++) {
    int t_status =
      pthread_create(&dec_thread_ids[i], NULL, do_decrement_work, NULL);
    if (t_status == -1) {
      perror("Error creating thread.");
      return 1;
    }
  }
  for (int i = 0; i < threads; i++) {
    int join_status = 
      pthread_join(dec_thread_ids[i], NULL);
    if (join_status == -1) {
      perror("Error joining thread.");
      return 2;
    }
  }

  printf("Finishing main \n");

  return 0;
}
