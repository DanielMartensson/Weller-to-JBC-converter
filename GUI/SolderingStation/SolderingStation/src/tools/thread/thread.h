#pragma once

typedef struct {
	int a;
}THREAD_DATA;

bool startThread();
bool stopThread();
void setData(const THREAD_DATA* threadData);
THREAD_DATA* getData();