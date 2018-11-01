FROM node:6

RUN yarn global add bs-platform

COPY package.json yarn.lock ./

# RUN apt-get update && apt-get install -y --no-install-recommends apt-utils && apt-get install build-essential

# RUN apt-get build-essential

WORKDIR /usr/src/app



RUN yarn

COPY . .

EXPOSE 8080

CMD ["yarn start"] 
