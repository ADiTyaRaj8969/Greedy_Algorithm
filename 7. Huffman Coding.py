"""
Huffman Coding
Task: Given a set of characters and their frequencies, build the Huffman Tree and generate the
Huffman codes for each character (lossless compression).
Greedy strategy: Always merge the two nodes with the lowest frequencies first (using a min-heap).
"""
import heapq

class Node:
    __slots__ = ("ch","freq","left","right")
    def __init__(self, ch=None, freq=0, left=None, right=None):
        self.ch, self.freq, self.left, self.right = ch, freq, left, right
    def __lt__(self, other):
        return self.freq < other.freq

def build_codes(root, path, codes):
    if not root:
        return
    if not root.left and not root.right:
        codes[root.ch] = path or "0"
        return
    build_codes(root.left, path+"0", codes)
    build_codes(root.right, path+"1", codes)

def huffman_codes(chars, freqs):
    pq = [Node(ch=c, freq=f) for c, f in zip(chars, freqs)]
    heapq.heapify(pq)
    while len(pq) > 1:
        a = heapq.heappop(pq)
        b = heapq.heappop(pq)
        heapq.heappush(pq, Node(freq=a.freq+b.freq, left=a, right=b))
    root = pq[0]
    codes = {}
    build_codes(root, "", codes)
    return codes

if __name__ == "__main__":
    chars = list("abcdef")
    freqs = [5,9,12,13,16,45]
    codes = huffman_codes(chars, freqs)
    for k in sorted(codes):
        print(f"{k}: {codes[k]}")
    # Time Complexity: O(k log k) — heap merges for k symbols.
    # Space Complexity: O(k) — heap and tree nodes.
