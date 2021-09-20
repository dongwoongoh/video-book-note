import { Prop, Schema, SchemaFactory } from '@nestjs/mongoose';
import { Document } from 'mongoose';

export type MetadataDocument = MetadataInformation & Document;

@Schema()
export class MetadataInformation {
  @Prop({ required: true })
  userId: string;

  @Prop({ required: true })
  comment: string;

  @Prop({ required: true })
  date: string;
}

export const metadataSchema = SchemaFactory.createForClass(MetadataInformation);
