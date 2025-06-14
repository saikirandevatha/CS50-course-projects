select distinct(people.name) from people, ratings, directors where directors.movie_id = ratings.movie_id AND directors.person_id = people.id AND ratings.rating >= '9.0';
