// Function to compute the greatest common divisor using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Structure to store slope fractions
typedef struct {
    int dx;
    int dy;
    int count;
} SlopeCount;

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) {
        return pointsSize;
    }

    int max_points = 1;

    for (int i = 0; i < pointsSize; i++) {
        int duplicate = 1;
        int vertical = 0;
        int local_max = 0;

        // Use a simple array to store unique slopes for the current anchor point i.
        // Since pointsSize <= 300, max unique slopes will not exceed 300.
        int dx_arr[300];
        int dy_arr[300];
        int counts[300];
        int slope_count = 0;

        for (int j = i + 1; j < pointsSize; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                duplicate++;
                continue;
            }

            if (dx == 0) {
                vertical++;
                continue;
            }

            // Reduce fraction to its simplest form
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            // Ensure consistent sign for slopes (e.g., make dx positive)
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }

            // Find or insert the slope in our temporary list
            int found = 0;
            for (int k = 0; k < slope_count; k++) {
                if (dx_arr[k] == dx && dy_arr[k] == dy) {
                    counts[k]++;
                    if (counts[k] > local_max) {
                        local_max = counts[k];
                    }
                    found = 1;
                    break;
                }
            }
            if (!found) {
                dx_arr[slope_count] = dx;
                dy_arr[slope_count] = dy;
                counts[slope_count] = 1;
                if (1 > local_max) {
                    local_max = 1;
                }
                slope_count++;
            }
        }

        // Account for vertical lines and duplicate points
        if (vertical > local_max) {
            local_max = vertical;
        }

        int total = local_max + duplicate;
        if (total > max_points) {
            max_points = total;
        }
    }

    return max_points;
}