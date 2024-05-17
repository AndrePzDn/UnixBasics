#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int g_v = 0;
pthread_mutex_t gv_mutex;

void* do_increment_work(int* count) {
  printf("Count is %d\n", *count);
  *count = *count + 1;
  pthread_t t_id =  pthread_self();
  printf("Thread[%lu] - doing increment work...\n", t_id);
  // Lock
  pthread_mutex_lock(&gv_mutex);
  g_v++;
  // Unlock
  pthread_mutex_unlock(&gv_mutex);
  printf("Thread[%lu] -  inc: g_v[%d].\n", t_id, g_v);
  printf("Thread[%lu] - increment done.\n", t_id);
  return NULL;
}

void* do_decrement_work() {
  pthread_t t_id =  pthread_self();
  printf("Thread[%lu] - doing decrement work...\n", t_id);
  // Lock
  pthread_mutex_lock(&gv_mutex);
  g_v--;
  // Unlock
  pthread_mutex_unlock(&gv_mutex);
  printf("Thread[%lu] -  dec: g_v[%d].\n", t_id, g_v);
  printf("Thread[%lu] - done decrement.\n", t_id);
  return NULL;
}


int main(int argc, char** argv) {

  int threads = 8;
  int count = 0;
  pthread_t inc_thread_ids[threads];
  pthread_t dec_thread_ids[threads];
  pthread_mutex_init(&gv_mutex, NULL);

  for (int i = 0; i < threads; i++) {
    int t_status =
      pthread_create(&inc_thread_ids[i], NULL, do_increment_work, (*void)&count);
    if (t_status == -1) {
      perror("Error creating thread.");
      return 1;
    }
  }

  for (int i = 0; i < threads; i++) {
    int t_status =
      pthread_create(&inc_thread_ids[i], NULL, do_increment_work, (*void)&count);
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

  pthread_mutex_destroy(&gv_mutex);
  printf("Finishing main \n");

  return 0;
}
