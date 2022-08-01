#include <iostream>
#include <vector>



struct Man {
    int index;
    int path;
    bool worked;
    int width;
    int height;

    Man *startX;
    Man *startY;
    Man *endX;
    Man *endY;

    Man(int index, int width, int height, int path, bool used) {
        this->index = index;
        this->width = width;
        this->height = height;
        this->path = path;
        this->worked = used;
        this->startX = nullptr;
        this->startY = nullptr;
        this->endX = nullptr;
        this->endY = nullptr;
    }
};


int parent(int i) {
    int temp = (i - 1) / 2;
    return temp;
}

bool comp(Man *a, Man *b) {
    if (!a->worked && !b->worked) {
        return a->path > b->path;
    }
    return a->worked && !b->worked;
}

int left(int i) {
    int temp = 2 * i + 1;
    return temp;
}

int right(int i) {
    int temp = 2 * i + 2;
    return temp;
}

void top(Man **heap, int i) {
    while (i > 0 && comp(heap[parent(i)], heap[i])) {
        std::swap(heap[i]->index, heap[parent(i)]->index);
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void down(Man **heap, int n, int i) {
    int j = i;
    if (left(i) < n && comp(heap[j], heap[left(i)])) {
        j = left(i);
    }
    if (right(i) < n && comp(heap[j], heap[right(i)])) {
        j = right(i);
    }
    if (i != j) {
        std::swap(heap[i]->index, heap[j]->index);
        std::swap(heap[i], heap[j]);
        down(heap, n, j);
    }
}

int getCell(char cell) {
    switch (cell) {
        case '.':
            return 1;
        case 'W':
            return 2;
        case '#':
            return -1;
        default:
            return 0;
    }
}


int main() {

    int width, height, startX, startY, endX, endY;
    std::cin >> width >> height >> startX >> startY >> endX >> endY;
    startX -= 1;
    startY -= 1;
    endX -= 1;
    endY -= 1;

    Man **heapOfDots = new Man *[1000000];
    int count = 0;

    std::vector<std::vector<char>> a;
    a.resize(width);
    for (int i = 0; i < width; i++) {
        a[i].resize(height);
        for (int j = 0; j < height; j++) {
            std::cin >> a[i][j];
        }
    }

    Man *startDot = nullptr;
    Man *endDot = nullptr;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            heapOfDots[count] = new Man(count, i, j, 100000000, false);
            if (getCell(a[i][j]) == -1) {
                heapOfDots[count]->worked = true;
            }
            if (i == startX && j == startY) {
                startDot = heapOfDots[count];
            }
            if (i == endX && j == endY) {
                endDot = heapOfDots[count];
            }
            if (j > 0) {
                heapOfDots[count]->endX = heapOfDots[count - 1];
                heapOfDots[count - 1]->endY = heapOfDots[count];
            }
            if (i > 0) {
                heapOfDots[count]->startX = heapOfDots[count - height];
                heapOfDots[count - height]->startY = heapOfDots[count];
            }
            count += 1;
        }
    }
    startDot->path = 0;
    top(heapOfDots, startDot->index);

    for (int i = count / 2 - 1; i >= 0; i--) {
        down(heapOfDots, count, i);
    }

    while (true) {
        Man *minDot = heapOfDots[0];
        if (minDot->worked == true) {
            break;
        }
        minDot->worked = true;
        down(heapOfDots, count, minDot->index);

        if (minDot->width > 0 && !minDot->startX->worked) {
            minDot->startX->path = std::min(minDot->startX->path, minDot->path +
                                                             getCell(a[minDot->width - 1][minDot->height]));
            top(heapOfDots, minDot->startX->index);
        }
        if (minDot->width < width - 1 && !minDot->startY->worked) {
            minDot->startY->path = std::min(minDot->startY->path,
                                       minDot->path + getCell(a[minDot->width + 1][minDot->height]));
            top(heapOfDots, minDot->startY->index);
        }
        if (minDot->height > 0 && !minDot->endX->worked) {
            minDot->endX->path = std::min(minDot->endX->path, minDot->path + getCell(a[minDot->width][minDot->height - 1]));
            top(heapOfDots, minDot->endX->index);
        }
        if (minDot->height < height - 1 && !minDot->endY->worked) {
            minDot->endY->path = std::min(minDot->endY->path,
                                     minDot->path + getCell(a[minDot->width][minDot->height + 1]));
            top(heapOfDots, minDot->endY->index);
        }
    }

    int result = endDot->path;
    if (result == 100000000) {
        result = -1;
    }
    std::cout << result << std::endl;

    if (result != -1) {
        std::vector<char> path;
        Man *prevDot = endDot;

        while (prevDot->width != startX || prevDot->height != startY) {
            if (prevDot->startX &&
                prevDot->path - getCell(a[prevDot->width][prevDot->height]) == prevDot->startX->path) {
                path.push_back('S');
                prevDot = prevDot->startX;
            } else if (prevDot->startY &&
                       prevDot->path - getCell(a[prevDot->width][prevDot->height]) == prevDot->startY->path) {
                path.push_back('N');
                prevDot = prevDot->startY;
            } else if (prevDot->endX &&
                       prevDot->path - getCell(a[prevDot->width][prevDot->height]) == prevDot->endX->path) {
                path.push_back('E');
                prevDot = prevDot->endX;
            } else if (prevDot->endY &&
                       prevDot->path - getCell(a[prevDot->width][prevDot->height]) == prevDot->endY->path) {
                path.push_back('W');
                prevDot = prevDot->endY;
            }
        }

        for (int i = path.size() - 1; i >= 0; i--) {
            std::cout << path[i];
        }
    }
}
