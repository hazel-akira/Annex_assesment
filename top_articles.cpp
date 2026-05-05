#include <bits/stdc++.h>
using namespace std;

struct Article {
    string name;
    int comments;
};

bool compare(const Article &a, const Article &b) {
    if (a.comments != b.comments)
        return a.comments > b.comments;   // primary: descending comments
    return a.name > b.name;               // secondary: descending name
}

vector<string> topArticles(int limit) {
    vector<Article> articles;

    int total_pages = 1; 
    // NOTE: In real system, this is provided by API response.
    // We assume pagination runs from page 1 to total_pages.

    for (int page = 1; page <= total_pages; page++) {

        // -----------------------------
        // MOCKED DATA REPRESENTATION
        // (In real test, this comes from API page response)
        // -----------------------------
        vector<map<string, string>> data;

        for (auto &item : data) {

            string name = "";

            // title OR story_title
            if (!item["title"].empty() && item["title"] != "null")
                name = item["title"];
            else if (!item["story_title"].empty() && item["story_title"] != "null")
                name = item["story_title"];
            else
                continue;

            int comments = 0;

            if (!item["num_comments"].empty() && item["num_comments"] != "null")
                comments = stoi(item["num_comments"]);

            articles.push_back({name, comments});
        }
    }

    // Sort by:
    // 1. num_comments DESC
    // 2. name DESC
    sort(articles.begin(), articles.end(), compare);

    vector<string> result;

    for (int i = 0; i < limit && i < (int)articles.size(); i++) {
        result.push_back(articles[i].name);
    }

    return result;
}