/*
 * Write a C program to simulate producer
 * consumer problem using semaphores.
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 5

/* Shared Variables */
