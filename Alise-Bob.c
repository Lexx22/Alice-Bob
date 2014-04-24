/*
 * Без имени.c
 * 
 * Copyright 2014 Lex <lex22@ubuntu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


// Alice a, p, q
// Bob b, p, q
// A = p^a mod q, B = p^b mod
// Key = p^b mod q
// a || b - ?

#include <stdio.h>

Int A, B, p, q, thread_count, key;
pthread_mutex_t mutex;
pthread_mutex_t cond;
pthread_t threads[thread_count];

Int pow(Int p, Int a, Int q){
	for(; a > 0; --a){
		p *= p;
		p %= q;
	}
	return p;
}

void key_found(Int a){
	pthread_mutex_lock(&mutex);
	key = pow(B, a, q);
	pthread_t self_id = pthread_self();
	pthread_mutex_signal(&cond);
	int i = 0;
	for(i = 0; i < thread_count, ++i){
		if(!pthread_equal(threads[i], self_id)){
			pthread_cancel(th[i]);
		}
	}
	pthread_mutex_unlock(&mutex);
}

/*

 pthread_mutex_t mutex;
 pthread_mutex_init(&mutex, NULL);
 pthread_mutex_unlock(&mutex);
 pthread_mutex_trylock(&mutex);
 pthread_mutex_destroy(&mutex);
 
 pthread_cond_t cond;
 pthread_cond_init(&cond, NULL);
 pthread_cond_signal(&cond);
 pthread_cond_broadcast(&cond);
 pthread_cond_wait(&cond, &mutex);
 
 pthread_cond_destroy(&cond);
 
 */
 
 /*
 
 mpz_t num;
 mpz_init(num); // num = 0;
 mpz_clear(num);
 mpz_powm(res, num, exp, mod);// res = num ^ exp % mod;
 mpz_init_set_str(num, str, 10);
 mpz_out_str(stdout, num, 10);
 mpz_t add(res, num1, num2); // res = num1 + num2
 
 */

void *calc(void *p){
	//will change
	Int id = *(int *)p;
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	Int left = 1000 * id, right = 1000 + left;
	int i = 0;
	for(i = left, i = right, ++i){
		Int tmp = pow(p, i, q);
		if(tmp == A){
			key_found(i);
			break;
		}
		pthread_exit(NULL););
 /*
 pthread_mutex_unlock(&mutex);
 pthread_mutex_trylock(&mutex);
 pthread_mutex_destroy(&mutex);
 
 pthread_cond_t cond;
 pthread_cond_init(&cond, NULL);
 pthread_cond_signal(&cond);
 pthread_cond_broadcast(&cond);
 pthread_cond_wait(&cond, &mutex);
 
 pthread_cond_destroy(&cond);
 
 */

void *calc(void *p){
	//will change
	Int id = *(int *)p;
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	Int left = 1000 * id, right = 1000 + left;
	Int i = 0;
	for(i = left, i = right, ++i){
		Int tmp = pow(p, i, q);
		if(tmp == A){
			key_found(i);
			break;
		}
		pthread_exit(NULL);
	}
}

int main(int argc, char **argv){
	//Int a = ...;
	int A = pow(p, a, q);
	Int id[thread_count];
	int i = 0;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&cond, NULL);
	pthread_mutex_lock(&mutex);
	
	for(i = 0; i < thread_count; ++i){
		id[i] = i;
	}
	for(i = 0; i < thread_count; ++i){
		pthread_create(&threads[i], NULL, calc, &id[i]);
	}
	pthread_cond_wait(&cond, &mutex)	
	printf("%d\n", key);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);	
	return 0;
}

