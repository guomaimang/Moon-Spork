Now I'll introduce the Implementation of the core algorithm of search. 

We try to break through important issues in search field ——speed.

In the preview, we embedded Elasticsearch into the commercial project of cloud service. 

In actual project, we need to consider scalability and application scenarios.

Combined with the usage, we not only created original search algorithm, but also improved ElasticSearch to make it more suitable for our needs. 

While retaining the Json format, we also redesigned the reverse index algorithm.

We realize that behind the simple sentences, the designer's wisdom is embodied. In terms of reverse index, 

As you can see, there are two tables, One is the keywords, the other records the weight of keywords and its relationship with documents. 

We only need to find the field corresponding to each ID.

It can index to our target document, and at the same time add the weight. 

These tables exist in the form of C++ Class.

In addition, we also tried B-Tree and dichotomy algorithm.



 

