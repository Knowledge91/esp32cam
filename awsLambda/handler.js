'use strict';

// var AWS = require('aws-sdk')
// var s3 = new AWS.S3({region: 'eu-west-1'})
const { WebClient } = require('@slack/web-api');

const token = process.env.SLACK_TOKEN
const web = new WebClient(token);

module.exports.esp32S3ImageUpload = async (event, context, callback) => {
  const body = JSON.parse(event.body) // image has to be base64 string
  var buf = Buffer.from(body.image, 'base64')

  var params = {
    Body: buf,
    Bucket: "sant-pacia-3",
    Key: "HappyFace.png",
  }

  await web.files.upload({
    filename: 'test.png',
    file: buf,
    channels: '#everyone',
  })

  callback(null, {body: "Success"})

  // await s3.putObject(params).promise()
  //   .then(function(data) {
  //     console.log('Success')
  //   }).catch(function(err) {
  //     console.log(err)
  //     callback(null, {body: "Failed"})
  //   })
};
