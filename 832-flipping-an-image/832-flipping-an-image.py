class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        c = len(image[0]) # length of column
        
        for row in image:
                for i in range((c + 1) // 2):
                    # swapping as well as changing the bit
                    row[i], row[c - 1 - i] = 1 - row[c - 1 - i], 1 - row[i]
            
        return image