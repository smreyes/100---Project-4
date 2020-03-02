/*
 *
 *
 *
 */

#ifndef ACTORNODE_HPP
#define ACTORNODE_HPP

#include <string>
#include <queue>
#include <vector>

using namespace std;

class actorNode {

	public:
		string actorName;
		unsigned int distance; //distance from the query node
		bool isDone; // set true if node was visited in BFS during shortest path
		actorNode* prevActor; // previous actor in the shortest path
		movieNode* prevMovie; //previous movie in shortest pth;
		
		unordered_map<string, edge*> adj;
		vector<edgeNode*> connections;

		explicit actorNode(string& actorName);

		//comparator for PQ in pathfinder
		struct compareDistance {
			bool operator() (actorNode*& n1, actorNode*& n2) {
				if (n1->distance == n2->distance) {
					return n1->actorName > n2->actorName;
				} else {
					return n1->distance > n2->distance;
				}
			}
		}; 


		/*
		void add (actorNode* actor, const pair<string, int>& info) {
			if (!adj.count(actor->actorName))
			adj[actor->actorName] = new edge(actor, info.first, info.second);
		}*/

		~actorNode() {};
		
};


#endif