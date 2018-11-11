class Solution(object):
    def minAreaRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        x_map, y_map = {}, {}
        for point in points:
            if point[0] in x_map:
                x_map[point[0]].append(point[1])
            else:
                x_map[point[0]] = [point[1]]
            if point[1] in y_map:
                y_map[point[1]].append(point[0])
            else:
                y_map[point[1]] = [point[0]]
        x_vals, y_vals = x_map.keys(), y_map.keys()
        for x in x_vals:
            if len(x_map[x]) < 2:
                del x_map[x]
            else:
                x_map[x] = sorted(x_map[x])
        for y in y_vals:
            if len(y_map[y]) < 2:
                del y_map[y]
            else:
                y_map[y] = sorted(y_map[y])
        x_vals, y_vals = sorted(x_map.keys()), sorted(y_map.keys())
        res = 1e20
        for x in x_vals:
            ys = x_map[x]
            for i in range(len(ys)-1):
                y1 = ys[i]
                if y1 not in y_map:
                    continue
                for j in range(i + 1, len(ys)):
                    y2 = ys[j]
                    if y2 not in y_map:
                        continue
                    for c in sorted(list(set(y_map[y1]) & set(y_map[y2]))):
                        if c > x:
                            res = min((c - x) * (y2 - y1), res)
        return res if res != 1e20 else 0
                
