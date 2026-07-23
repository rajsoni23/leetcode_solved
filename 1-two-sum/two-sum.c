typedef struct {
    int key;
    int value;
    bool used;
} HashEntry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    int tableSize = numsSize * 2 + 1;
    HashEntry* map = (HashEntry*)calloc(tableSize, sizeof(HashEntry));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        unsigned int hash = (unsigned int)labs(complement) % tableSize;
        while (map[hash].used) {
            if (map[hash].key == complement) {
                result[0] = map[hash].value;
                result[1] = i;
                free(map);
                return result;
            }
            hash = (hash + 1) % tableSize;
        }

        hash = (unsigned int)labs(nums[i]) % tableSize;
        while (map[hash].used) {
            hash = (hash + 1) % tableSize;
        }
        map[hash].key = nums[i];
        map[hash].value = i;
        map[hash].used = true;
    }

    free(map);
    *returnSize = 0;
    return NULL;
}