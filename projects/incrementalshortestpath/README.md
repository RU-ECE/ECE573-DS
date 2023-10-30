# Incremental Shortest Path

This concept is due to Raghav Daga. If you are given a graph of paths such as current airline  flights, you can calculate optimal cost using Floyd-Warshall which is $O(V^3)$. But since paths change in realtime, what if you can come up with an incremental algorithm to compute the new cheapest paths if the data changes? For example, if only a single airfare changed, why should you have to recompute everything?

This project will require you to setup a virtual set of costs. It would be lovely to pull in ticket pricing for airplanes, but that's probably way too hard. If you want, you can try to find a source where you can read in a text file of costs, but I assume  you will not be able to find one. This means you need to create your own fictitious situation (airfares, trainfares, whatever). Then you solve the cheapest way to get from every point to every other using Floyd-Warshall on your large, fake dataset. Then you devise an algorithm to do it much faster incrementally.