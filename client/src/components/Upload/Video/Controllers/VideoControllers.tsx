import React from "react";
import { useContext } from "react";
import { videosApiContext } from "../../../../api/video/VideoApi";
import {
  VideoDispatchContext,
  VideoStateContext,
} from "../../../../contexts/VideoContexts";
import { VideoFormState } from "../../../../types/data/video/form.type";
import VideoForm from "../Form/VideoForm";

const VideoControllers = () => {
  const api = useContext(videosApiContext);
  const state = useContext(VideoStateContext);
  const dispatch = useContext(VideoDispatchContext);

  const handleSubmitBtn = async (e: React.FormEvent<HTMLFormElement>) => {
    e.preventDefault();

    const formData = new FormData();
    formData.append("video", state!.uploadForm!.video!);
    formData.append("title", state!.uploadForm!.title!);
    formData.append("description", state!.uploadForm!.description!);
    formData.append("theme", state!.uploadForm!.theme!);

    const res = await api.upload(formData);

    console.log(res.data);
    window.location.href = "/videos";
  };

  const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const { name, value, files } = e.currentTarget;

    dispatch!({
      type: "VIDEO_UPLOAD",

      uploadForm: {
        ...state!.uploadForm,
        [name]: files ? files[0] : value,
      } as VideoFormState,
    });
  };

  const handleChangeTextArea = (e: React.ChangeEvent<HTMLTextAreaElement>) => {
    dispatch!({
      type: "VIDEO_UPLOAD",

      uploadForm: {
        ...state!.uploadForm,
        description: e.currentTarget.value,
      } as VideoFormState,
    });
  };

  const handleSelectedChange = (e: React.ChangeEvent<HTMLSelectElement>) => {
    dispatch!({
      type: "VIDEO_UPLOAD",

      uploadForm: {
        ...state!.uploadForm,
        theme: e.currentTarget.value,
      } as VideoFormState,
    });
  };

  return (
    <VideoForm
      handleSelectedChange={handleSelectedChange}
      handleChange={handleChange}
      handleSubmitBtn={handleSubmitBtn}
      handleChangeTextArea={handleChangeTextArea}
    />
  );
};

export default VideoControllers;
