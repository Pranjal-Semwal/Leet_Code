import heapq

class Solution(object):
    def assignTasks(self, servers, tasks):
        """
        :type servers: List[int]
        :type tasks: List[int]
        :rtype: List[int]
        """
        # available: min-heap of (weight, server_index)
        available = [(weight, idx) for idx, weight in enumerate(servers)]
        heapq.heapify(available)
        
        # busy: min-heap of (time_free, weight, server_index)
        busy = []
        
        m = len(tasks)
        ans = [0] * m
        current_time = 0
        
        for j, duration in enumerate(tasks):
            # A task cannot be processed before its arrival time j
            current_time = max(current_time, j)
            
            # If all servers are occupied, fast-forward time to the next completion
            if not available:
                current_time = busy[0][0]
            
            # Release all servers that finish on or before current_time
            while busy and busy[0][0] <= current_time:
                _, weight, idx = heapq.heappop(busy)
                heapq.heappush(available, (weight, idx))
            
            # Assign the best server to the current task
            weight, idx = heapq.heappop(available)
            ans[j] = idx
            heapq.heappush(busy, (current_time + duration, weight, idx))
            
        return ans