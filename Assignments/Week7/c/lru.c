#include <stdio.h>
#include <stdbool.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames) {
    int frames[num_frames]; //current in memory
    int last_used[num_frames]; //lastused at which time
    int page_faults = 0;

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (int time = 0; time < num_requests; time++) {
        int page = page_requests[time]; //this page is requested
        bool hit = false;

        for (int i = 0; i < num_frames; i++) { //check current frames
            if (frames[i] == page) { //if found
                hit = true; //found
                last_used[i] = time; //update the recent time
                break;
            }
        }

        if (hit) //no page fault
            continue;

        page_faults++; //page fault occured

        int frame_index = -1;

        for (int i = 0; i < num_frames; i++) {
            if (frames[i] == -1) { //looking for empty frame here
                frame_index = i; //found 
                break;
            }
        }

        if (frame_index == -1) { //not found empty space have to remove something
            frame_index = 0;

            for (int i = 1; i < num_frames; i++) {
                if (last_used[i] < last_used[frame_index]) //find least recently value of time of a frame
                    frame_index = i;
            }
        }
        frames[frame_index] = page; //update the lowest 
        last_used[frame_index] = time; //update the time frame also 
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int num_requests = sizeof(requests) / sizeof(requests[0]);

    simulate_lru(requests, num_requests, 3);

    return 0;
}