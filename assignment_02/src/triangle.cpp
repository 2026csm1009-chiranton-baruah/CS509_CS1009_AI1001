#include "triangle.h"

int countTriangles(
    const vector<int>& offset,
    const vector<int>& edges,
    vector<vector<int>>& triangles
)
{
    int vertices = offset.size() - 1;
    int count = 0;

    for (int u = 0; u < vertices; u++)
    {
        for (int i = offset[u]; i < offset[u + 1]; i++)
        {
            int v = edges[i];

            if (v <= u)
            {
                continue;
            }

            for (int j = offset[v]; j < offset[v + 1]; j++)
            {
                int w = edges[j];

                if (w <= v)
                {
                    continue;
                }

                bool connected = false;

                for (int k = offset[u]; k < offset[u + 1]; k++)
                {
                    if (edges[k] == w)
                    {
                        connected = true;
                        break;
                    }
                }

                if (connected)
                {
                    vector<int> triangle;
                    triangle.push_back(u);
                    triangle.push_back(v);
                    triangle.push_back(w);

                    triangles.push_back(triangle);
                    count++;
                }
            }
        }
    }

    return count;
}
